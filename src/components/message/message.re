open Reducer;

let style = (message) => switch message {
| Bot => "message-bot"
| User => "message-user"
};

let name = (owner) => switch owner {
  | Bot => ReactDOMRe.Style.make(
          ~margin="0.5em 0px 0.5em 1.5em",
          ~textAlign="left",
          ()
        )
  | User => ReactDOMRe.Style.make(
          ~margin="0.5em 1.5em 0.5em 0px",
          ~textAlign="right",
          ()
        )
  };

let component = ReasonReact.statelessComponent("Message");
let make = (~message: message, _children) => {
  ...component,
  render: _self => {
    <div>
    <p style=name(message.owner)>{ReasonReact.string(switch message.owner {
    | User => "Vous"
    | Bot => "ChatBot";
    })}</p>
    <div className=style(message.owner)> 
      <span style= {
          ReactDOMRe.Style.make(
            ~lineHeight="1.5",
            ()
          )
        }> {ReasonReact.string(message.message)} 
      </span> 
    </div>
    </div>;
  },
};
