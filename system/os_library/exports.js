var exec = require('child_process').exec;
function execute(command, callback){
    exec(command, function(error, stdout, stderr){ callback(stdout); });
};

function countArgs(arglist)
{
  if (arglist == "")
    return 0;
  return arglist.split(",").length;
}

var demangled = [], mangled = [];

var source = require("fs").readFileSync("./source/library.cpp").toString();

var method = {};
var lines = source.split("\n");
var namespace = [];
for (var i in lines)
{
  var line = lines[i];
  var matchBeginNamespace = line.match("namespace (.*)");
  if (matchBeginNamespace)
  {
    namespace.push(matchBeginNamespace[1]);
  }
  var matchEndNamespace = line.match("^\\s*}\\s*$");
  if (matchEndNamespace)
  {
    namespace.pop();
  }
  var matchDecl = line.match("^\\s*([a-zA-Z\\*0-9_]*)\\s*(\\w*)\\s*\\((.*)\\)");
  if (matchDecl)
  {
    var decl = matchDecl[1];
    if (decl.substr(0, 1) == "E") // local enum
      decl = namespace.join("::") + "::" + decl;

    var key = namespace.join("::") + "::" + matchDecl[2] + "$" + countArgs(matchDecl[3]);
    if (method[key])
      console.log("//Conflicting method: " + key);
    else
      method[key] = decl;
  }
}

var _path = "/Users/gabrielvalky/Downloads/gcc-arm-none-eabi-7-2018-q2-update/bin/";
execute(_path + "arm-none-eabi-nm --demangle ./build/libbios.so", out =>
{
  var lines = out.split("\n");
  for (var i in lines)
  {
    var tokens = lines[i].match("^.* T (.*)$")
    if (tokens && tokens.length == 2)
      demangled.push(tokens[1]);
  }

  execute(_path + "arm-none-eabi-nm ./build/libbios.so", out =>
  {
    var lines = out.split("\n");
    for (var i in lines)
    {
      var tokens = lines[i].match("^.* T (.*)$")

      if (tokens && tokens.length == 2)
        mangled.push(tokens[1]);
    }
    finish();
  })

});


function finish()
{
/*
  console.log(`// Automatically generated

uint32_t GetProcAddress(char* symbol)
{
  if (strncmp(symbol, "_ZN4BIOS", 8) == 0)
  {
    symbol += 8;
  } else
  if (strncmp(symbol, "_ZN3GUI", 7) == 0)
  {
    symbol += 7;
  } else
  if (strncmp(symbol, "_ZN7PRIVATE", 11) == 0)
  {
    symbol += 11;
  } else
  if (strncmp(symbol, "_Z", 2) == 0)
  {
    symbol += 2;
  } else
  {
    return 0;
  }

  while (*symbol >= '0' && *symbol <= '9')
    symbol++;

  uint32_t hash = 5381;
  uint8_t c;
  while (c = *symbol++)
    hash = ((hash << 5) + hash) + c;

  switch (hash)
  {`);

  for (var i = 0; i<demangled.length; i++)
  {
    var tokens = demangled[i].match("^(.*?)\\((.*)\\)$")
    var mname = mangled[i];
    mname = ("$"+mname).replace("$_ZN4BIOS", "").replace("$_ZN3GUI", "").replace("$_Z7", "");
    while ("0123456789".indexOf(mname.substr(0, 1)) != -1)
      mname = mname.substr(1);

    var retvalue = method[tokens[1] + "$" + countArgs(tokens[2])];
    console.log('  if (strcmp(symbol, "' + mname + '") == 0)');
    if (!retvalue)
      console.log('    return (uint32_t)' + tokens[1] + ';');
    else
      console.log('    return (uint32_t)static_cast<'+retvalue+'(*)(' + tokens[2] + ')>(' + tokens[1] + '); ');
  }
*/

  console.log(`// Automatically generated by exports.js

uint32_t GetProcAddress(char* symbol)
{
  uint32_t hash = 5381;
  uint8_t c;
  while ((c = *symbol++) != 0)
    hash = hash*37 + c;

  switch (hash & 0x0000ffff)
  {`);

  var wasGpio = false;
  var wasAdc = false;
  for (var i = 0; i<demangled.length; i++)
  {
    var tokens = demangled[i].match("^(.*?)\\((.*)\\)$")
    var mname = mangled[i];
//    mname = ("$"+mname).replace("$_ZN4BIOS", "").replace("$_ZN3GUI", "").replace("$_Z7", "");
//    while ("0123456789".indexOf(mname.substr(0, 1)) != -1)
//      mname = mname.substr(1);

    var retvalue = method[tokens[1] + "$" + countArgs(tokens[2])];
//    console.log('  if (strcmp(symbol, "' + mname + '") == 0)');
    var out = "    case "+hash(mname)+": ";

    var isGpio = tokens[1].indexOf("GPIO") != -1;
    var isAdc  = tokens[1].indexOf("ADC") != -1 || tokens[1].indexOf("DAC") != -1;

    if (isGpio && !wasGpio)
      console.log("#if defined(LA104)")
    if (!isGpio && wasGpio)
      console.log("#endif")

    wasGpio = isGpio;

    if (isAdc && !wasAdc)
      console.log("#if defined(DS203) || defined(DS213)")
    if (!isAdc && wasAdc)
      console.log("#endif")

    wasAdc = isAdc;

    if (!retvalue)
      out += 'return (uint32_t)' + tokens[1] + ';';
    else
      out += 'return (uint32_t)static_cast<'+retvalue+'(*)(' + tokens[2] + ')>(' + tokens[1] + '); ';
//    console.log(out + " // " + mname);
    console.log(out);
  }           
  console.log(`    default: return 0;
  }
}
`)
//  console.log('  return 0;\n}\n');
}              


function hash(str)
{
  var h = 5381;
  for (var i = 0; i<str.length; i++)
    h = (h * 37 + str.charCodeAt(i)) >>> 0;
//  h &= 0xffffffff;
  h = h >>> 0;
  h &= 0x0000ffff;

  return "0x"+("00000000" + h.toString(16)).substr(-8);
}
