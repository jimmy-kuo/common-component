/*
 *  Author: wangqiying
 *  Created on: 20170623
 */
#include <stdio.h>
#include <iostream>
#include <Benchmark.h>
#include "msg.pb.h"
#include "pb2json.h"

using namespace std;

int main()
{
    Request request;
    request.mutable_header()->set_user("hello-every-users");
    request.mutable_header()->set_passwd("11223344556677889900abcd");
    request.set_arg1(101);
    request.add_arg2(10100000000000001LL);
    request.add_arg2(1022222201LL);
    request.set_arg3(3.14159265357);

    Arg* arg = request.add_args();
    arg->set_f1("xf1");
    arg->set_f2("xf2");
    arg = request.add_args();
    arg->set_f1("xff1");
    arg->set_f2("xff2");
    
    Body* b = request.add_bodys();
    b->set_sid(87654321);
    b->set_data("In this section, I will try to explain how the components work together so that you can understand the relationships among them");

    b = request.add_bodys();
    b->set_sid(87654322);
    b->set_data("The Xbox was launched in 2002 as Microsoft's rival to the Sony PlayStation and Nintendo 's GameCube, with the more powerful Xbox 360 going on sale three years later.");

    Benchmark t;
    t.start();
    string str;
    for(int i = 0; i < 100000; ++i)
    {
        str.clear();
        pb2json::pb2json(&request, str);
    }
    t.stop();
    cout << "#################################################" << endl;
    cout << "pb2json total cost:" << t.computeTimeInMilliseconds() << "ms" << endl;  
    cout << "pb2json result:" << endl;
    cout << str << endl;

    cout << "#################################################" << endl;
    Request new_req;
    string err;
    int ret = pb2json::json2pb(str, &new_req, err);
    cout << "json2pb result: " << ret << endl;
    cout << "pb content: " << endl;
    cout << new_req.DebugString();
    cout << "#################################################" << endl;
    return 0;
}

