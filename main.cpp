#include <iostream>
#include <vector>
#include <string>
#include "fcgi.h"
#include <stdio.h>

int main(int argc,char **argv) {

    ::FastCgi fc;
  fc.setRequestId(1);
  fc.startConnect();
  fc.sendStartRequestRecord();
  fc.sendParams("SCRIPT_FILENAME","/home/changke/fastcgi/www/Hello.php");
  fc.sendParams("REQUEST_METHOD","GET");
  fc.sendEndRequestRecord();
  std::string tmp = fc.readFromPhp();
  std::cout << tmp << std::endl ;
  return 0;
}
