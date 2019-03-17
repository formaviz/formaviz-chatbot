open Reducer;

type position =
  | BottomRight
  | BottomLeft;

module IndexStyle = {
  let indexDiv = {
    ReactDOMRe.Style.make(
      ~display="flex",
      ~justifyContent="space-between",
      ~flexDirection="column",
      ~height="100%",
      ~backgroundColor="#f9f9f9",
      ~borderColor="rgba(0,0,0,0.08)",
      ~color="#656565",
      (),
    );
  };
};


let makePosition = pos =>
  switch (pos) {
  | BottomRight =>
    ReactDOMRe.Style.make(
      ~position="absolute",
      ~bottom="0",
      ~right="1rem",
      ~boxShadow="0 10px 16px 0 rgba(0,0,0,0.2),0 6px 20px 0 rgba(0,0,0,0.19)",
      ~width="300px",
      (),
    )
  | BottomLeft =>
    ReactDOMRe.Style.make(
      ~position="absolute",
      ~bottom="0",
      ~left="1rem",
      ~boxShadow="0 10px 16px 0 rgba(0,0,0,0.2),0 6px 20px 0 rgba(0,0,0,0.19)",
      ~width="300px",
      (),
    )
  };

  let component = ReasonReact.reducerComponent("Chatbot");
  let make = (~isAuthenticated, ~position: position, _children) => {
    ...component,
    initialState: () => initialAppState,
    reducer,
    render: ({state, send}) =>
      <div style={makePosition(position)}>
        <div style=IndexStyle.indexDiv>
          <Header ctx={show: state.show} appSend=send />
          {state.show ?
             <div>
               <Conversation ctx={messages: state.messages, isAuthenticated: isAuthenticated} />
               <Input ctx={inputValue: state.input, isAuthenticated: isAuthenticated} appSend=send />
             </div> :
             ReasonReact.null}
        </div>
      </div>,
  };

[@bs.deriving abstract]
  type jsProps = {
     isAuthenticated: bool,
     position: position,
  };

  let default =
    ReasonReact.wrapReasonForJs(~component, jsProps =>
      make(
        ~isAuthenticated=jsProps->isAuthenticatedGet,
        ~position=jsProps->positionGet,
        [||],
      )
    );