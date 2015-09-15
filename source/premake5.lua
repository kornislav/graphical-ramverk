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

	require 'engine'
	require 'dev_app'
