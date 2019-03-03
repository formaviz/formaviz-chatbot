open Reducer;

module InputStyle = {
  let send_button = (isAuthenticated)  => {
    ReactDOMRe.Style.make(
      ~border="none",
      ~cursor= (isAuthenticated) ? "text" : "not-allowed",
      ());
  };

  let message_group = {
    ReactDOMRe.Style.make(
      ~borderColor="inherit",
      ~color="#656565",
      ~backgroundColor="#fff",
      ~padding="10px 16px",
      ~flex="0 0 auto",
      ~display="flex",
      ~flexDirection="row",
      ~margin="0",
      (),
    );
  };

  let input_value = (isAuthenticated)  => {
    ReactDOMRe.Style.make(
      ~width="100%",
      ~border="none",
      ~cursor= (isAuthenticated) ? "text" : "not-allowed",
      ~outline="none", 
      ());
  };
};

type ctx = {inputValue: string, isAuthenticated: bool};

let component = ReasonReact.statelessComponent("Input");
let make = (~ctx: ctx, ~appSend, _children) => {
  ...component,
  render: _self => {
    <form
      autoComplete="off"
      style=InputStyle.message_group
      onSubmit={ev => {
        ReactEvent.Form.preventDefault(ev);
        appSend(AddMessage);
      }}>
      <input
        id="message"
        type_="text"
        autoComplete="off"
        value={ctx.inputValue}
        style=InputStyle.input_value(ctx.isAuthenticated)
        placeholder="Inserez votre message ici ..."
        onChange={ev => {
          let value = ReactEvent.Form.target(ev)##value;
          appSend(UpdateInput(value));
        }}
        disabled={!ctx.isAuthenticated}
      />
      <button 
        type_="submit" 
        style=InputStyle.send_button(ctx.isAuthenticated) 
        disabled={!ctx.isAuthenticated}> 
          <i className="fa fa-arrow-circle-right" />
      </button>
    </form>;
  },
};
