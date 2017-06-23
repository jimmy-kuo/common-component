/*
 *Copyleft jimmy.gj
 *Base on yinqiwen <yinqiwen@gmail.com>
 *All rights reserved.
 *
 */

#ifndef PB2JSON_H
#define PB2JSON_H

#include <string>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>
#include "document.h"

#define ERR_INVALID_ARG -1
#define ERR_INVALID_PB -2
#define ERR_UNKNOWN_FIELD -3
#define ERR_INVALID_JSON -4

namespace pb2json
{
    void pb2json(const google::protobuf::Message* msg, std::string& str);
    rapidjson::Value* pb2jsonobject(const google::protobuf::Message* msg);
    rapidjson::Value* pb2jsonobject(const google::protobuf::Message* msg, rapidjson::Value::AllocatorType& allocator);
    void json2string(const rapidjson::Value* json, std::string& str);

    int json2pb(const std::string& json, google::protobuf::Message* msg, std::string& err);
    int jsonobject2pb(const rapidjson::Value* json, google::protobuf::Message* msg, std::string& err);
}


#endif /* PB2JSON_HPP */
