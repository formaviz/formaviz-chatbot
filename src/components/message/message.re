type message =
  | Bot
  | User;

let getMessage = state => {};

let component = ReasonReact.statelessComponent("message");
let make = _childre => {
  ...component,
  render: _self => {
    <div className=""> <span> {this.props.message} </span> </div>;
  },
};
