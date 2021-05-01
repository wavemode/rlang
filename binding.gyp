{
    "targets": [
	{
	    "target_name": "rlang",
	    "include_dirs": [
		"<!@(node -p \"require('node-addon-api').include\")",
		"vendor/R/include"
	    ],
	    "libraries": [
		"-lR"
	    ],
	    "sources": [
		"src/rlang.cc"
	    ],
	    "defines": [
		"NAPI_DISABLE_CPP_EXCEPTIONS"
	    ]
	}
    ]
}
