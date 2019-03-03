const dialogflow = require('dialogflow');
const fs = require('fs');
const uuid = require('uuid');
const logger = require('../logger');
	
const LANGUAGE_CODE = 'fr-FR' 

module.exports = class DialogFlow {
	constructor () {
        const obj = JSON.parse(fs.readFileSync('resources/newagent-861d2-74fa9273f51e.json', 'utf8'));

        this.projectId = obj.project_id
        
		const config = {
			credentials: {
				private_key: obj.private_key,
				client_email: obj.client_email,
			}
		}
	
		this.sessionClient = new dialogflow.SessionsClient(config)
    }
    
    async sendTextMessageToDialogFlow(textMessage) {
        const sessionId = uuid.v4();

		// Define session path
		const sessionPath = this.sessionClient.sessionPath(this.projectId, sessionId);

		const request = {
			session: sessionPath,
			queryInput: {
				text: {
					text: textMessage,
					languageCode: LANGUAGE_CODE
				}
			}
		}
		try {
			const responses = await this.sessionClient.detectIntent(request)			
			logger.info('DialogFlow.sendTextMessageToDialogFlow: Detected intent');
			return responses
		}
		catch(err) {
			logger.error('DialogFlow.sendTextMessageToDialogFlow ERROR:', err);
			throw err
		}
	}
}