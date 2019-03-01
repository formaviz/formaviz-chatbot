module InputStyle = {
  open Css;

  let sendButton = style([color(white), backgroundColor(darkgray)]);

  let inputGroup = style([display(`flex), paddingTop(`rem(1.0)), height(`rem(1.5))]);

  let formControl = style([width(`percent(100.0))]);
};

let component = ReasonReact.statelessComponent("Input");
let make = _children => {
  ...component,
  render: _self => {
    <div className=InputStyle.inputGroup>
      <input type_="text" className=InputStyle.formControl placeholder="Inserez votre message ici ..." />
      <button className=InputStyle.sendButton> {ReasonReact.string("Send")} </button>
    </div>;
  },
};
