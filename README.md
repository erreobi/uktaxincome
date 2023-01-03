# uktaxincome
It is my first example of web assembly. I decided to create a simple page that calculates your tax income ... 


# Compile
emcc helloworld.c -o hello.html

emcc helloworld.c -o output/hello5.html --shell-file ./html_template/my_template.html -s NO_EXIT_RUNTIME=1 -s "EXPORTED_RUNTIME_METHODS=['ccall']"

# Run a WebServer
python3 -m http.server --cgi 8080

# docs

[]{https://www.youtube.com/watch?v=RSLHrmDL4kU}