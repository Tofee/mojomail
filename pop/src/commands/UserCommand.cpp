// @@@LICENSE
//
//      Copyright (c) 2009-2013 LG Electronics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// LICENSE@@@

#include "commands/UserCommand.h"
#include "client/PopSession.h"
#include <iostream>

const char* const UserCommand::COMMAND_STRING		= "USER";

UserCommand::UserCommand(PopSession& session, const std::string& user)
: PopProtocolCommand(session),
  m_user(user)
{

}

UserCommand::~UserCommand()
{

}

void UserCommand::RunImpl()
{
	if (!m_session.HasNetworkError()) {
		MojLogInfo(m_log, "Sending USER command");

		std::string userCommand = COMMAND_STRING + (" " + m_user);
		SendCommand(userCommand);
	} else {
		MojLogInfo(m_log, "Abort user command due to network");
		Complete();
	}
}

MojErr UserCommand::HandleResponse(const std::string& line)
{
	if (m_status == Status_Ok) {
		MojLogDebug(m_log, "USER command +OK");
		m_session.UserOk();
	} else {
		MojLogDebug(m_log, "USER command -ERR");
		m_session.LoginFailure(MailError::BAD_USERNAME_OR_PASSWORD, m_serverMessage);
	}

	Complete();
	return MojErrNone;
}
