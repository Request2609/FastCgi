#include <iostream>
#include<string.h>
#include"fcgi.h"
int main()
{
    ::FastCgi fc ;
    //设置请求编号
    fc.setRequestId(1) ;
    //连接服务器php-fpm
    fc.startConnect() ;
    fc.sendStartRequestRecord() ;

    //设置method 为post
    //设置script_name变量为php资源路径
    //设置content-type　文本格式
    //设置content-length消息长度
    //将要操作的数据传过去
    int len = strlen("a=20&b=10&c=5&d=6&name=ck") ;
    char ll[10] ;
    sprintf(ll, "%d", len) ;
    fc.sendParams("SCRIPT_FILENAME", "/home/changke/fastcgi/www/Operation.php");
    fc.sendParams("REQUEST_METHOD", "POST") ;
    fc.sendParams("CONTENT_LENGTH", ll) ;
    fc.sendParams("CONTENT_TYPE", "application/x-www-form-urlencoded") ;
    fc.sendEndRequestRecord() ;
    //构造头部
    FCGI_Header h = fc.makeHeader(FCGI_STDIN, 1, len, 0) ;
    fc.sendRequest(h) ;
    //发送消息
    fc.sendRequest(const_cast<char*>("a=20&b=10&c=5&d=6&name=ck"), len) ;
    //制造头部，告诉body结束
    FCGI_Header endHead = fc.makeHeader(FCGI_STDIN, 1, 0, 0) ;
    fc.sendRequest(endHead) ;
    std::cout << fc.readFromPhp() ;
    return 0;
}

