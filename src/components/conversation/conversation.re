open Reducer;
open Webapi.Dom;
open Element;

module ConversationStyle = {
  let conversation = {
    ReactDOMRe.Style.make(
      ~backgroundColor="#eee",
      ~height="300px",
      ~overflowY="auto",
      (),
    )
  };

  let no_connected_label = {
    ReactDOMRe.Style.make(
      ~textAlign="center",
      ~margin="2rem",
      (),
    )
  }

  let no_connected_link = {
    ReactDOMRe.Style.make(
      ~color="#00008f",
      ~cursor="pointer",
      (),
    )
  }
}

let setSectionRef = (theRef, {ReasonReact.state}) => {
  let foo = Webapi.Dom.document |> Document.querySelector("#foo");

  switch foo {
  | Some(a) =>  setScrollTop(a, scrollHeight(a) |> float_of_int);
  | None => Js.log("Nothing")
  };
}

type ctx = {messages: list(message), isAuthenticated: bool};

let component = ReasonReact.statelessComponent("Conversation");
let make = (~ctx: ctx, _children) => {
  ...component,
  render: ({handle, send}) => {
    <div id="foo" ref={handle(setSectionRef)} style=ConversationStyle.conversation>
    {
      (!ctx.isAuthenticated) ? 
        <div style=ConversationStyle.no_connected_label>
          <p>
            {ReasonReact.string("Vous etes actuellement deconnecte, ")}
            <a href="/login" style=ConversationStyle.no_connected_link>
              {ReasonReact.string("se connecter")}
            </a>
            {ReasonReact.string(" ou ")}
            <a href="/register" style=ConversationStyle.no_connected_link>
              {ReasonReact.string("s'enregistrer")}
              </a>
          </p>
        </div>
      : 
      <div>
        <Message message={owner: Bot, message:"Bonjour comment allez-vous aujourd'hui ?"}/>
        {
              ctx.messages
              |> Array.of_list
              |> Array.mapi((index, message) =>
                    <Message key=(string_of_int(index)) message/>
                  )
              |> ReasonReact.array
        }
      </div>
    }
    </div>;
  },
};