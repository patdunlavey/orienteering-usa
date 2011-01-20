<?php
// $Id: $
/**
 * @file
 * Integrate Views
 */

/**
 * Implementation of hook_views_data().
 */
function ms_core_views_data() {
  $data = array();

  // Definitions for ms_order_adjustments
  $data['ms_order_adjustments']['table']['group'] = t('Adjustment');
  $ms_order_adjustments = drupal_get_schema('ms_order_adjustments');
  $data['ms_order_adjustments']['table']['join'] = array(
    'ms_orders' => array(
      'left_field' => 'oid',
      'field' => 'oid',
      'type' => 'INNER',
    ), 
  );
  //varchar
  $data['ms_order_adjustments']['id'] = array(
    'title' => 'ID',
    'help' => $ms_order_adjustments['fields']['id']['description'],
    'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
        'handler' => 'views_handler_argument_string',
    ),
  );
  //varchar
  $data['ms_order_adjustments']['type'] = array(
    'title' => 'Type',
    'help' => $ms_order_adjustments['fields']['type']['description'],
    'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
        'handler' => 'views_handler_argument_string',
    ),
  );
  //varchar
  $data['ms_order_adjustments']['display'] = array(
    'title' => 'Display',
    'help' => $ms_order_adjustments['fields']['display']['description'],
    'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
        'handler' => 'views_handler_argument_string',
    ),
  );
  //numeric
  $data['ms_order_adjustments']['value'] = array(
    'title' => 'Value',
    'help' => $ms_order_adjustments['fields']['value']['description'],
    'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_float',
    ),
    'argument' => array(
        'handler' => 'views_handler_argument_float',
    ),
  );
  //int
  $data['ms_order_adjustments']['weight'] = array(
    'title' => 'Weight',
    'help' => $ms_order_adjustments['fields']['weight']['description'],
    'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
        'handler' => 'views_handler_argument_numeric',
    ),
  );
 // Definitions for ms_order_products
  $data['ms_order_products']['table']['group'] = t('Product');
  $ms_order_products = drupal_get_schema('ms_order_products');
  $data['ms_order_products']['table']['join'] = array(
    'ms_orders' => array(
      'left_field' => 'oid',
      'field' => 'oid',
      'type' => 'INNER',
    ),
  );
  //varchar
  $data['ms_order_products']['type'] = array(
    'title' => 'Type',
    'help' => $ms_order_products['fields']['type']['description'],
    'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
        'handler' => 'views_handler_argument_string',
    ),
  );
  //int
  $data['ms_order_products']['id'] = array(
    'title' => 'ID',
    'help' => $ms_order_products['fields']['id']['description'],
    'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
        'handler' => 'views_handler_argument_numeric',
    ),
  );
  //varchar
  $data['ms_order_products']['name'] = array(
    'title' => 'Name',
    'help' => $ms_order_products['fields']['name']['description'],
    'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
        'handler' => 'views_handler_argument_string',
    ),
  );
  //varchar
  $data['ms_order_products']['module'] = array(
    'title' => 'Module',
    'help' => $ms_order_products['fields']['module']['description'],
    'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
        'handler' => 'views_handler_argument_string',
    ),
  );
  //int
  $data['ms_order_products']['qty'] = array(
    'title' => 'Qty',
    'help' => $ms_order_products['fields']['qty']['description'],
    'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
        'handler' => 'views_handler_argument_numeric',
    ),
  );
  //numeric
  $data['ms_order_products']['amount'] = array(
    'title' => 'Amount',
    'help' => $ms_order_products['fields']['amount']['description'],
    'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_float',
    ),
    'argument' => array(
        'handler' => 'views_handler_argument_float',
    ),
  );
  //text
  $data['ms_order_products']['recurring_schedule'] = array(
    'title' => 'Recurring Schedule',
    'help' => $ms_order_products['fields']['recurring_schedule']['description'],
    'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
        'handler' => 'views_handler_argument_string',
    ),
  );
 // Definitions for ms_orders
  $data['ms_orders']['table']['group'] = t('Order');
  $data['ms_orders']['table']['base'] = array(
    'field' => 'oid',
    'title' => t('Order'),
    'help' => t("Create Order Related Views"),
    'weight' => -10,
  );
  $ms_orders = drupal_get_schema('ms_orders');
  //serial
  $data['ms_orders']['oid'] = array(
    'title' => 'ID',
    'help' => $ms_orders['fields']['oid']['description'],
    'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
        'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['users']['table']['join'] = array(
    'ms_orders' => array(
      'left_field' => 'uid',
      'field' => 'uid',
      'type' => 'INNER',
    ), 
  );
  $data['users_roles']['table']['join'] = array(
    'ms_orders' => array(
      'left_field' => 'uid',
      'field' => 'uid',
      'type' => 'INNER',
    ), 
  );
  //varchar
  $data['ms_orders']['status'] = array(
    'title' => 'Status',
    'help' => $ms_orders['fields']['status']['description'],
    'field' => array(
        'handler' => 'ms_core_order_status_handler',
        'click sortable' => TRUE,
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
        'handler' => 'views_handler_argument_string',
    ),
  );
  //varchar
  $data['ms_orders']['order_type'] = array(
    'title' => 'Type',
    'help' => $ms_orders['fields']['order_type']['description'],
    'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
        'handler' => 'views_handler_argument_string',
    ),
  );
  //varchar
  $data['ms_orders']['gateway'] = array(
    'title' => 'Gateway',
    'help' => $ms_orders['fields']['gateway']['description'],
    'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
        'handler' => 'views_handler_argument_string',
    ),
  );
  //numeric
  $data['ms_orders']['amount'] = array(
    'title' => 'Amount',
    'help' => $ms_orders['fields']['amount']['description'],
    'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_float',
    ),
    'argument' => array(
        'handler' => 'views_handler_argument_float',
    ),
  );
  //varchar
  $data['ms_orders']['currency'] = array(
    'title' => 'Currency',
    'help' => $ms_orders['fields']['currency']['description'],
    'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
        'handler' => 'views_handler_argument_string',
    ),
  );
  //int
  $data['ms_orders']['secured'] = array(
    'title' => 'Secured?',
    'help' => $ms_orders['fields']['secured']['description'],
    'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
        'handler' => 'views_handler_argument_numeric',
    ),
  );
  //text
  $data['ms_orders']['recurring_schedule'] = array(
    'title' => 'Recurring Schedule',
    'help' => $ms_orders['fields']['recurring_schedule']['description'],
    'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
        'handler' => 'views_handler_argument_string',
    ),
  );
  //varchar
  $data['ms_orders']['full_name'] = array(
    'title' => 'Full Name',
    'help' => $ms_orders['fields']['full_name']['description'],
    'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
        'handler' => 'views_handler_argument_string',
    ),
  );
  //text
  $data['ms_orders']['shipping_address'] = array(
    'title' => 'Shipping Address',
    'help' => $ms_orders['fields']['shipping_address']['description'],
    'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
        'handler' => 'views_handler_argument_string',
    ),
  );
  //text
  $data['ms_orders']['billing_address'] = array(
    'title' => 'Billing Address',
    'help' => $ms_orders['fields']['billing_address']['description'],
    'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
        'handler' => 'views_handler_argument_string',
    ),
  );
  //int
  $data['ms_orders']['created'] = array(
    'title' => 'Created',
    'help' => $ms_orders['fields']['created']['description'],
    'field' => array(
        'handler' => 'views_handler_field_date',
        'click sortable' => TRUE,
    ),
    'sort' => array(
        'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_date',
    ),
    'argument' => array(
        'handler' => 'views_handler_argument_date',
    ),
  );
  //int
  $data['ms_orders']['modified'] = array(
    'title' => 'Modified',
    'help' => $ms_orders['fields']['modified']['description'],
    'field' => array(
        'handler' => 'views_handler_field_date',
        'click sortable' => TRUE,
    ),
    'sort' => array(
        'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_date',
    ),
    'argument' => array(
        'handler' => 'views_handler_argument_date',
    ),
  );
 // Definitions for ms_payments
  $data['ms_payments']['table']['group'] = t('Payment');
  $ms_payments = drupal_get_schema('ms_payments');
  $data['ms_payments']['table']['join'] = array(
    'ms_orders' => array(
      'left_field' => 'oid',
      'field' => 'oid',
      'type' => 'INNER',
    ), 
  );
  //varchar
  $data['ms_payments']['type'] = array(
    'title' => 'Type',
    'help' => $ms_payments['fields']['type']['description'],
    'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
        'handler' => 'views_handler_argument_string',
    ),
  );
  //varchar
  $data['ms_payments']['transaction'] = array(
    'title' => 'Transaction #',
    'help' => $ms_payments['fields']['transaction']['description'],
    'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
        'handler' => 'views_handler_argument_string',
    ),
  );
  //varchar
  $data['ms_payments']['gateway'] = array(
    'title' => 'Gateway',
    'help' => $ms_payments['fields']['gateway']['description'],
    'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
        'handler' => 'views_handler_argument_string',
    ),
  );
  //numeric
  $data['ms_payments']['amount'] = array(
    'title' => 'Amount',
    'help' => $ms_payments['fields']['amount']['description'],
    'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_float',
    ),
    'argument' => array(
        'handler' => 'views_handler_argument_float',
    ),
  );
  //varchar
  $data['ms_payments']['currency'] = array(
    'title' => 'Currency',
    'help' => $ms_payments['fields']['currency']['description'],
    'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
        'handler' => 'views_handler_argument_string',
    ),
  );
  //text
  $data['ms_payments']['recurring_schedule'] = array(
    'title' => 'Recurring Schedule',
    'help' => $ms_payments['fields']['recurring_schedule']['description'],
    'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
        'handler' => 'views_handler_argument_string',
    ),
  );
  //int
  $data['ms_payments']['created'] = array(
    'title' => 'Created',
    'help' => $ms_payments['fields']['created']['description'],
    'field' => array(
        'handler' => 'views_handler_field_date',
        'click sortable' => TRUE,
    ),
    'sort' => array(
        'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_date',
    ),
    'argument' => array(
        'handler' => 'views_handler_argument_date',
    ),
  );
  //int
  $data['ms_payments']['Modified'] = array(
    'title' => 'modified',
    'help' => $ms_payments['fields']['modified']['description'],
    'field' => array(
        'handler' => 'views_handler_field_date',
        'click sortable' => TRUE,
    ),
    'sort' => array(
        'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_date',
    ),
    'argument' => array(
        'handler' => 'views_handler_argument_date',
    ),
  );

  
  return $data;
}
