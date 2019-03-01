module IndexStyle = {
  open Css;

  let indexDiv = style([display(`flex), justifyContent(`center), flexDirection(`column)]);
};

module Index = {
  let component = ReasonReact.statelessComponent("Index");
  let make = _children => {
    ...component,
    render: _self => {
      <div className=IndexStyle.indexDiv> <Header /> <Input /> </div>;
    },
  };
};

ReactDOMRe.renderToElementWithId(<Index />, "main");
