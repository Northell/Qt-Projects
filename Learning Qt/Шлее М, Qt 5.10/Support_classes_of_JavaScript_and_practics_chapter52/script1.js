// ======================================================================
//  script.js --
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

function showFiles()
{
    var files = JsTools.dirEntryList(".", "*");
    JsTools.alert(files.join("\n"));
}

JsTools.print("JsTools test!");
cmdFiles.clicked.connect(showFiles);
cmdQuit.clicked.connect(function(){JsTools.quitApplication()});
