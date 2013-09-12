
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_test.h"
#include "test.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Cache\Frontend\Json
 *
 * Allows to cache data converting/deconverting them to JSON.
 *
 * This adapter uses the json_encode/json_decode PHP's functions
 *
 * As the data is encoded in JSON other systems accessing the same backend could
 * process them
 *
 *<code>
 *<?php
 *
 * // Cache the data for 2 days
 * $frontCache = new Phalcon\Cache\Frontend\Json(array(
 *    "lifetime" => 172800
 * ));
 *
 * //Create the Cache setting memcached connection options
 * $cache = new Phalcon\Cache\Backend\Memcache($frontCache, array(
 *		'host' => 'localhost',
 *		'port' => 11211,
 *  	'persistent' => false
 * ));
 *
 * //Cache arbitrary data
 * $cache->save('my-data', array(1, 2, 3, 4, 5));
 *
 * //Get data
 * $data = $cache->get('my-data');
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_Frontend_Json) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Cache\\Frontend, Json, phalcon, cache_frontend_json, phalcon_cache_frontend_json_method_entry, 0);

	zend_declare_property_null(phalcon_cache_frontend_json_ce, SL("_frontendOptions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Cache\Frontend\Base64 constructor
 *
 * @param array frontendOptions
 */
PHP_METHOD(Phalcon_Cache_Frontend_Json, __construct) {

	zval *frontendOptions = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &frontendOptions);

	if (!frontendOptions) {
		ZEPHIR_CPY_WRT(frontendOptions, ZEPHIR_GLOBAL(global_null));
	}


	zephir_update_property_this(this_ptr, SL("_frontendOptions"), frontendOptions TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}
