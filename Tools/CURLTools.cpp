//
// Created by aj on 5/16/16.
//
#define _GLIBCXX_USE_CXX11_ABI 0 //Fixes linking errors with curlpp on newer GCC versions
//TODO: Recompile curlpp so I don't need this

#include "CURLTools.h"

using namespace cURLpp;
using namespace std;

/**
 * Retrieves an XML file and stores it in the XMLMemoryUnit class
 */
void RetrieveXMLFile(Glib::ustring URL, XMLMemoryUnit * data) {
    try {
        Cleanup cleaner;
        Easy easyGrab;

        types::WriteFunctionFunctor functor(data, &XMLMemoryUnit::WriteCallback);

        easyGrab.setOpt(new Options::Encoding("UTF-8"));
        easyGrab.setOpt(new Options::Verbose(true));
        easyGrab.setOpt(new Options::Url(URL.c_str()));
        easyGrab.setOpt(new Options::WriteFunction(functor));

        easyGrab.perform();
    } catch (exception &e) {
        cout << e.what() << endl;
    }
}

