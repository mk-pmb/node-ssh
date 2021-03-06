#ifndef NODE_SSH_CHAN_H
#define NODE_SSH_CHAN_H

#define protected public
#define private public

#include <node.h>
#include <node_object_wrap.h>
#include <node_events.h>
#include <node_buffer.h>
#include <v8.h>

#include <libssh/libssh.h>
#include <libssh/server.h>
#include <libssh/callbacks.h>

#include <deque>
#include <utility>

using namespace v8;
using namespace node;

class Chan : EventEmitter {
public:
    ssh_channel channel;
    std::deque< std::pair<int, char *> > buffers;
    bool done;
    
    Chan();
    
    static Persistent<FunctionTemplate> constructor_template;
    static Handle<Value> New(const Arguments &);
    static Handle<Value> Create(ssh_channel);
    static Handle<Value> Write(const Arguments &);
    static void Initialize();
    
    static int ReadChannel(eio_req *);
    static int ReadChannelAfter(eio_req *);
};
    
#endif
