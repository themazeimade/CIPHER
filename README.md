# CIPHER
Cipher exercise, just run the executable and see the magic.
## Compile it
Only tested on windows but 100% sure it works on linux (Vulkan FTW)
if you are crazy like me use the MinGW64 makefiles, otherwise make the visual studio build files.
If the project uses vulkan, make sure you have installed the SDK and set as an enviroment variable in your OS system/session.
<pre>
  mkdir build
  cd build
  //either
  cmake -G "MinGW Makefiles" .. -DCMAKE_BUILD_TYPE=Debug
  //or
  cmake -G "Visual Studio 15" .. -DCMAKE_BUILD_TYPE=Debug
  //finally
  cmake --build . --config Debug
</pre>
