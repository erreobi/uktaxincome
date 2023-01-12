# Uk_tax_income 
It is my first example of web assembly. I decided to create a simple page that calculates your uk tax income ... 


# How to compile Compile

``` bash
emcc ukTaxCalculator.c  -o output/ukTaxCalculator.js 
```

## examples 
emcc helloworld.c -o hello.html

emcc helloworld.c -o output/hello5.html --shell-file ./html_template/my_template.html -s NO_EXIT_RUNTIME=1 -s "EXPORTED_RUNTIME_METHODS=['ccall']"

emcc helloworld.c -o output/hello5.html --shell-file ./html_template/my_template.html -s NO_EXIT_RUNTIME=1 -s "EXPORTED_RUNTIME_METHODS='ccall','cwrap'"


# Run a WebServer on local
python3 -m http.server --cgi 8080

# docs

[Really good tutorial](https://www.youtube.com/watch?v=RSLHrmDL4kU)

[Nice explanation tutorial](https://marcoselvatici.github.io/WASM_tutorial/)
