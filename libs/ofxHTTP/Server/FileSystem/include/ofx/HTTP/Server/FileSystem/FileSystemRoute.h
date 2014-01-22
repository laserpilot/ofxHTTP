// =============================================================================
//
// Copyright (c) 2013 Christopher Baker <http://christopherbaker.net>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// =============================================================================


#pragma once


#include "ofx/HTTP/Server/FileSystem/FileSystemRouteHandler.h"
#include "ofx/HTTP/Server/FileSystem/FileSystemRouteInterface.h"
#include "ofx/HTTP/Server/FileSystem/FileSystemRouteSettings.h"


namespace ofx {
namespace HTTP {


class FileSystemRoute: public FileSystemRouteInterface
{
public:
    typedef std::shared_ptr<FileSystemRoute> SharedPtr;
    typedef std::weak_ptr<FileSystemRoute>   WeakPtr;
    typedef FileSystemRouteSettings Settings;

    FileSystemRoute(const Settings& settings);
    virtual ~FileSystemRoute();

    virtual void handleRequest(Poco::Net::HTTPServerRequest& request,
                               Poco::Net::HTTPServerResponse& response);

    virtual bool canHandleRequest(const Poco::Net::HTTPServerRequest& request,
                                  bool isSecurePort) const;

    Poco::Net::HTTPRequestHandler* createRequestHandler(const Poco::Net::HTTPServerRequest& request);

    FileSystemRouteSettings getSettings() const;

    static SharedPtr makeShared(const Settings& settings)
    {
        return SharedPtr(new FileSystemRoute(settings));
    }

private:
    Settings _settings;

};

    
} } // namespace ofx::HTTP