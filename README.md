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

Add this line to ```html <head></head> ``` :

```html
 <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.7.2/css/all.css" integrity="sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr" crossorigin="anonymous">
```

Have fun.
Team formaviz.


