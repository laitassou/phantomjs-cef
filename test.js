console.log('Loading a web page');
var page = require('webpage').create();
var url = 'http://phantomjs.org';
page.open(url, function (status) {
  if (status === "fail") {
    phantom.exit();
  }
  console.log("status callback: " + status);
  console.log("eval ret val:" + page.evaluate(function() {
    console.log("window.location.hostname = " + window.location.hostname);
    return window.location.hostname;
  }, function(retval) {
    console.log("retval: " + retval);
    phantom.exit();
  }, function(errorCode, errorMessage) {
    console.log("execution failed :( code = " + errorCode + ", message = " + errorMessage);
    phantom.exit();
  }));
});
console.log("exiting?");

setTimeout(function() { console.log("Timeout!"); }, 1000);
