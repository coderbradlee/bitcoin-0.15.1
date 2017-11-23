#include "base58.h"
#include "chain.h"
#include "coins.h"
#include "consensus/validation.h"
#include "core_io.h"
#include "init.h"
#include "keystore.h"
#include "validation.h"
#include "merkleblock.h"
#include "net.h"
#include "policy/policy.h"
#include "policy/rbf.h"
#include "primitives/transaction.h"
#include "rpc/server.h"
#include "rpc/client.h"
#include "script/script.h"
#include "script/script_error.h"
#include "script/sign.h"
#include "script/standard.h"
#include "txmempool.h"
#include "uint256.h"
#include "utilstrencodings.h"
#ifdef ENABLE_WALLET
#include "wallet/rpcwallet.h"
#include "wallet/wallet.h"
#endif
#include <boost/algorithm/string.hpp>
#include <stdint.h>

#include <univalue.h>

#include "interface.h"
// #include <stdlib.h>
// #include <stdio.h>
std::string Callcreaterawtransaction(std::string args)
{
    std::vector<std::string> vArgs;
    boost::split(vArgs, args, boost::is_any_of(" \t"));
    std::string strMethod = vArgs[0];
    vArgs.erase(vArgs.begin());
    JSONRPCRequest request;
    request.strMethod = strMethod;
    request.params = RPCConvertValues(strMethod, vArgs);
    request.fHelp = false;
    // BOOST_CHECK(tableRPC[strMethod]);
    rpcfn_type method = tableRPC[strMethod]->actor;
    try {
        UniValue result = (*method)(request);
        return result.get_str();
    }
    catch (const UniValue& objError) {
        // throw std::runtime_error(find_value(objError, "message").get_str());
        // throw "Callcreaterawtransaction";
        return "";
    }
    return "";
}

char* createrawtransaction(voidstar f,const char* reqjson)
{
	//UniValue createrawtransaction(const JSONRPCRequest& request)
	// JSONRPCRequest request;
 //    request.strMethod = "createrawtransaction";
 //    request.params = RPCConvertValues(strMethod, vArgs);
 //    request.fHelp = false;
	std::string req="createrawtransaction "+std::string(reqjson);
	// \"[{\"txid\":\"6c3f611cbd624e8a094f08b10f849b765d3548c13ace1704de050a44f504caff\",\"vout\":0}]\" \"{\"mxu9tvJsuZq1rxiaevcUJkuu6mv2LFhpSr\":0.1}\"";
	// bip44wallet * foo = (bip44wallet*)f;
  	// std::string ret=foo->Callcreaterawtransaction(reqjson);
  	std::string ret=Callcreaterawtransaction(reqjson);
	char *buf = (char *)malloc(ret.length());
	sprintf(buf, "%s", ret.c_str());
	return buf;
	// UniValue raw=Callcreaterawtransaction(req);
	// char *buf = (char *)malloc(raw.get_str().length());
	// sprintf(buf, "%s", raw.get_str().c_str());
	// return buf;

	// return raw.get_str().c_str();
}
