const express = require('express');
const cors = require('cors');
const helmet = require('helmet');
const hpp = require('hpp');
const DialogFlow = require('../model/dialogflow');
const logger = require('../logger');

const api = express();

api.use(cors())
api.use(express.json({ limit: '1mb' }));
api.use(helmet());
api.use(hpp());

const apiRoutes = express.Router();
apiRoutes
  .post('/', (req, res) => {
    logger.info(`🔥  Message : ${req.body.message}`);
    const dialogflow = new DialogFlow();
    const result = dialogflow.sendTextMessageToDialogFlow(req.body.message);
    result.then(values => {
        values.forEach(value => {
            if (value && value.queryResult) {
                value.queryResult.fulfillmentMessages.forEach(message => {
                    const returnValue = []
                    message.text.text.forEach(text => {
                        returnValue.push(text);
                    });
                    
                    console.log({
                        messages: returnValue
                    });

                    return res.status(200).send({
                        messages: returnValue
                    });
                });
            }
        });
    }).catch(err => logger.error(`🌎 Error : ${err}`));
  }
    
  ).use((err, req, res, next) => {
    res.status(403).send({
      success: false,
      message: `${err.name} : ${err.message}`,
    });
    next();
  });

api.use('/api', apiRoutes);

module.exports = api;