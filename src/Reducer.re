

type owner =
  | Bot
  | User;

type message = {
  owner,
  message: string,
};

type state = {
  show: bool,
  messages: list(message),
  input: string,
};

let initialAppState = {show: false, messages: [], input: ""};

type action =
  | UpdateShow(bool)
  | UpdateInput(string)
  | UpdateMessages(list(message))
  | AddMessage
  | ClearInput;


type test = {
  messages: list(string),
};

module Decode = {
  let test = json =>
    Json.Decode.{
      messages: json |> field("messages", list(string)),
    };
};

let reducer = (action, state) =>
  switch (action) {
  | UpdateShow(show) => ReasonReact.Update({...state, show})
  | UpdateInput(input) => ReasonReact.Update({...state, input})
  | UpdateMessages(messages) => 
    ReasonReact.UpdateWithSideEffects({...state, messages}, self => self.send(ClearInput))
  | AddMessage =>
    ReasonReact.UpdateWithSideEffects(
      {...state, show: true},
      self => {
        let value = self.state.input;
        let payload = Js.Dict.empty();
        Js.Dict.set(payload, "message", Js.Json.string(value));

        let values = self.state.messages @ [{owner: User, message: value}];
        self.send(UpdateMessages(values));

        let _ = Js.Promise.(
          Fetch.fetchWithInit(
            "http://localhost:1235/api",
            Fetch.RequestInit.make(
                ~method_=Post,
                ~body=Fetch.BodyInit.make(Js.Json.stringify(Js.Json.object_(payload))),
                ~headers=Fetch.HeadersInit.make({"Content-Type": "application/json"}),
                ()
            )
          )
          |> then_(Fetch.Response.json)
          |> then_(json => json  |> Decode.test |> (messages => messages) |> resolve)
          |> then_(json => json.messages |> List.map(text => {owner: Bot, message: text }) |> resolve)
          |> then_(json => values @ json |> resolve)
          |> then_(result => UpdateMessages(result) |> self.send |> resolve)
        );
      },
    )
  | ClearInput =>
    ReasonReact.Update({...state, input: ""});
  };
