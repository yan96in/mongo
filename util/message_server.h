// message_server.h

/*    Copyright 2009 10gen Inc.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

/*
  abstract database server
  async io core, worker thread system
 */

#pragma once

#include "../stdafx.h"

namespace mongo {
    
    class MessageHandler {
    public:
        virtual ~MessageHandler(){}
        virtual void process( Message& m , AbstractMessagingPort* p ) = 0;
    };
    
    class MessageServer {
    public:
        MessageServer( int port , MessageHandler * handler ) : _port( port ) , _handler( handler ){}
        virtual ~MessageServer(){}

        virtual void run() = 0;
        
    protected:
        
        int _port;
        MessageHandler* _handler;
    };

    MessageServer * createServer( int port , MessageHandler * handler );
}
