#define INDEX_HTML "<html> <head><script src=https://code.jquery.com/jquery-3.5.1.min.js integrity=\"sha256-9/aliU8dGd2tb6OSsuzixeV4y/faTqgFtohetphbbj0=\" crossorigin=anonymous>\n</script><link rel=stylesheet href=https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css integrity=sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T crossorigin=anonymous><script src=https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js integrity=sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1 crossorigin=anonymous>\n</script><script src=https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js integrity=sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM crossorigin=anonymous></script><script>\nconst key_enter = 13;\nconst key_up    = 38;\nconst key_down  = 40;\nconst key_right = 39;\nconst key_left  = 37;\nconst key_esc   = 27;\nconst key_space = 32;\nconst key_ctrl  = 17;\nconst key_alt   = 18;\nconst key_shift = 16;\n\nfunction updateConsole(data,status,jqXHR) {\n  $(\"#console\").html(data);\n}\n\nvar commands = {\n  stop: function() {\n    console.log(\"Stop\");\n    $.get(\"/stop\",null,updateConsole);\n  },\n  forward: function() {\n    console.log(\"Forward\");\n    $.get(\"/forward\",null,updateConsole)\n  },\n  backward: function() {\n    console.log(\"Backward\");\n    $.get(\"/backward\",null,updateConsole)\n  },\n  left: function() {\n    console.log(\"Left\");\n    $.get(\"/left\",null,updateConsole)\n  },\n  right: function() {\n    console.log(\"Right\");\n    $.get(\"/right\",null,updateConsole)\n  }\n}\n\n$(function() {\n  $(\"body\").keydown(function(evt) {\n    switch(evt.which) {\n       case key_up: \n         commands.forward();\n         break;\n       case key_down:\n         commands.backward();\n         break;\n      case key_right:\n         commands.right();\n         break;\n      case key_left:\n         commands.left();\n         break;\n      case key_space:\n         commands.stop();\n         break;\n    }\n  });\n\n  $(\"#stop\").click(commands.stop);\n  $(\"#forward\").click(commands.forward);\n  $(\"#backward\").click(commands.backward);\n  $(\"#left\").click(commands.left);\n  $(\"#right\").click(commands.right);\n});\n\n</script></head> <body> <div class=container-fluid> <div id=cam class=\"alert alert-secondary d-flex justify-content-center\" role=alert> <img id=stream src=/stream> </div> </div> <div class=container> <div class=\"row p-2\"> <div class=\"col-sm d-flex justify-content-center\"> </div> <div class=\"col-sm d-flex justify-content-center\"> <button id=forward type=button class=\"btn btn-dark\">Forward</button> </div> <div class=\"col-sm d-flex justify-content-center\"> </div> </div> <div class=\"row p-2\"> <div class=\"col-sm d-flex justify-content-center\"> <button id=left type=button class=\"btn btn-dark\">Left</button> </div> <div class=\"col-sm d-flex justify-content-center\"> <button id=stop type=button class=\"btn btn-dark\">Stop</button> </div> <div class=\"col-sm d-flex justify-content-center\"> <button id=right type=button class=\"btn btn-dark\">Right</button> </div> </div> <div class=\"row p-2\"> <div class=\"col-sm d-flex justify-content-center\"> </div> <div class=\"col-sm d-flex justify-content-center\"> <button id=backward type=button class=\"btn btn-dark\">Backward</button> </div> <div class=\"col-sm d-flex justify-content-center\"> </div> </div> </div> <div class=container-fluid> <div id=console class=\"alert alert-secondary d-flex justify-content-center\" role=alert> Welcome </div> </div> </body> </html> "
