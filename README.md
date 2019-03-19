# ChatBotComponents

## Install Project

To install the component chatbot, you need to do this :

```sh
npm i formaviz-chatbot
```

## Import and use component

To import the component, do like that :
```js
import Chatbot from 'formaviz-chatbot/dist/bundle';

<Chatbot isAuthenticated={true} position="BottomRight" />
```

For props :
    - isAuthenticated : true/false corresponding of user currently connected.
    - position: have two configuration : BottomLeft and BottomRight. By default, BottomRight is used it.

Then you need to import css like this :
```js
import 'formaviz-chatbot/dist/style.css';
```

Have fun.
Team formaviz.


