#include "../include/cppJoshi_bits/payoffConstructible.hpp"

namespace
{
    PayoffHelper<PayoffCall3> registerCall("call");
    PayoffHelper<PayoffPut3> registerPut("put");
}