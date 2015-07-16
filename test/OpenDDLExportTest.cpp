/*-----------------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2014-2015 Kim Kulling

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
-----------------------------------------------------------------------------------------------*/
#include "gtest/gtest.h"

#include <openddlparser/OpenDDLExport.h>
#include <openddlparser/DDLNode.h>

BEGIN_ODDLPARSER_NS

class OpenDDLExportTest : public testing::Test {
public:
    DDLNode *m_root;

protected:
    virtual void SetUp() {
        m_root = createNodeHierarchy();
    }

    virtual void TearDown() {
        delete m_root;
        m_root = ddl_nullptr;
    }

    DDLNode *createNodeHierarchy() {
        DDLNode *root = DDLNode::create( "test", "root" );
        for( uint32 i = 0; i < 10; i++ ) {
            DDLNode *node( DDLNode::create( "test", "child" ) );
            node->attachParent( root );
        }
        
        return root;
    }
};

TEST_F( OpenDDLExportTest, createTest ) {
    bool ok( true );
    try {
        OpenDDLExport myExport;
    } catch( ... ) {
        ok = false;
    }
    EXPECT_TRUE( ok );
}

TEST_F( OpenDDLExportTest, handleNodeTest ) {
    OpenDDLExport myExport;
     
    bool success( true );
    success = myExport.handleNode( m_root );
    EXPECT_TRUE( success );
}

END_ODDLPARSER_NS

