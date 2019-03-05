open Reducer;

module HeaderStyle = {
  let header_chatbot = {
    ReactDOMRe.Style.make(
      ~backgroundColor="#273ab0",
      ~color="white",
      ~display="flex",
      ~alignItems="center",
      ~justifyContent="space-between",
      ~cursor="pointer",
      (),
    )
  };

  let header_chatbot_title = {
    ReactDOMRe.Style.make(
      ~margin="1rem",
      (),
    )
  };

  let header_chatbot_exit ={
    ReactDOMRe.Style.make(
      ~margin="1rem",
      ~backgroundColor="transparent",
      ~color="white",
      ~border="none",
      (),
    )
  };
};

type ctx = {show: bool};

let component = ReasonReact.statelessComponent("Header");
let make = (~ctx: ctx, ~appSend, _children) => {
  ...component,
  render: _self => {
    <div style=HeaderStyle.header_chatbot onClick={ev => appSend(UpdateShow(!ctx.show))}>
      <h2 style=HeaderStyle.header_chatbot_title> {ReasonReact.string("Chatbot")} </h2>
      <button style=HeaderStyle.header_chatbot_exit> {
        ctx.show ? 
          <i className="fa fa-angle-down"></i> :
          <i className="fa fa-angle-up"></i>
      } </button>
    </div>;
  },
};
