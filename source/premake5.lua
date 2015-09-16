PRODUCT_NAME = 'Graphical RamVerk'

solution(PRODUCT_NAME)
	platforms {
		"Win32"
	}
	configurations {
		"Debug",
		"Release",
		"Final"
	}

	startproject "dev_app"

	require 'engine'
	require 'dev_app'
