let component = ReasonReact.statelessComponent("Conversation");
let make = _childre => {
  ...component,
  render: _self => {
    <div className="Conversation">
      <div className="container"> <Messages messages={this.props.messages} /> </div>
    </div>;
  },
};
