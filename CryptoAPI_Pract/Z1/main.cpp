#include <iostream>
#include <string>
#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/sha.h>
#include <cryptopp/channels.h>
#include <cryptopp/filters.h>

using namespace std;
using namespace CryptoPP;

int main ()
{
  try
  {
    SHA384 sha384;
    string hash;

    const char* FILE = "/home/user/.bash_logout";
	
    cout << "File name: " << FILE << endl;

    HashFilter filter(sha384, new HexEncoder(new StringSink(hash)));

    ChannelSwitch cs;
    cs.AddDefaultRoute(filter);

    FileSource(FILE, true, new Redirector(cs));

    cout << "Hash : " << hash << endl;
  }

  catch (const Exception &e)
  {
    cerr << e.what() << endl;
    return 1;
  }

  return 0;
}