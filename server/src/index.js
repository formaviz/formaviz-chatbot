const api = require('./api');
const logger = require('./logger');

const port = process.env.PORT || 1235;
const ip = process.env.IP || 'localhost';

api.listen(port, ip, err =>
    err
      ? logger.error(`🔥  Failed to start API : ${err.stack}`)
      : logger.info(`🌎  API is listening on ip ${ip} and port ${port}`)
  );