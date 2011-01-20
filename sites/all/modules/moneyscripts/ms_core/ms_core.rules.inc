<?php

// ======================================
// CONDITIONS
// ======================================

/* 
* Conditions:
* + Check the Status of an order
*/ 

/**
* Implementation of hook_rules_condition_info().
* @ingroup rules
*/
function ms_core_rules_condition_info() {
  return array(
    'ms_core_condition_order_status' => array(
      'label' => t('Check the status of the order'),
      'arguments' => array(
        'order' => array('type' => 'ms_order', 'label' => t('Order')),
        'status' => array('type' => 'ms_order_status', 'label' => t('Status'))
      ),
      'module' => 'MS Core',
    ),
  );
}

/**
* Condition: Check the value of a field.
*/
function ms_core_condition_order_status($order, $status) {
  if ($order->status == $status) {
    return TRUE;
  }
  return FALSE;
}

// ======================================
// ACTIONS
// ======================================

/* 
* Actions:
* + Change Order Status (Active, Cancelled, EOT, etc)
*/

/**
* Implementation of hook_rules_action_info().
* @ingroup rules
*/
function ms_core_rules_action_info() {
  return array(
    'ms_core_action_change_order_status' => array(
      'label' => t('Change the Status of an Order'),
      'arguments' => array(
        'order' => array('type' => 'ms_order', 'label' => t('Order')),
        'status' => array('type' => 'order_status', 'label' => t('Status')),
      ),
      'module' => 'MS Core',
    ),
  );
}

/**
* Action: Change the status of an Order
*/
function ms_core_action_change_order_status($order, $status) {
  // Change the Order Status
  return ms_core_set_order_status($order, $status);
}

// ======================================
// TRIGGERS
// ======================================

/* 
* Triggers:
* - Order is marked as completed
* - Order is marked as XXXXXXXX
* - Payment is received for an order
*/ 

/**
 * Implementation of hook_rules_event_info()
 */
function ms_core_rules_event_info() {
  $items = array(
    'ms_core_event_membership_cancel' => array(
      'label' => t('Membership Cancelled'),
      'module' => 'MS Core',
      'help' => t("Triggers when a membership is cancelled."),
      'arguments' => array(
        'account' => array('type' => 'user', 'label' => t('User Account')),
        'membership' => array('type' => 'membership', 'label' => t('Membership')),
        'm_plan' => array('type' => 'm_plan', 'label' => t('Membership Plan')),
      ),
    ),
  );
  
  return $items;
}


// ======================================
// DATA TYPES
// ======================================

/**
* Implementation of hook_rules_data_type_info().
*/
function ms_core_rules_data_type_info() {
  return array(
    'order_status' => array(
      'label' => t('Order Status'),
      'class' => 'rules_data_type_order_status',
      'savable' => FALSE,
      'identifiable' => FALSE,
      'uses_input_form' => TRUE,
      'module' => 'MS Core',
    ),
    'ms_order' => array(
      'label' => t('Order'),
      'class' => 'rules_data_type_ms_order',
      'savable' => FALSE,
      'identifiable' => TRUE,
      'uses_input_form' => FALSE,
      'module' => 'MS Core',
    ),
    'ms_payment' => array(
      'label' => t('Payment'),
      'class' => 'rules_data_type_ms_payment',
      'savable' => FALSE,
      'identifiable' => TRUE,
      'uses_input_form' => FALSE,
      'module' => 'MS Core',
    ),
  );
}

/**
* Defines the rules ms_payment data type.
*/
class rules_data_type_ms_payment extends rules_data_type {
  function load($pid) {
    return ms_core_load_payment($pid);
  }
  
  function get_identifier() {
    $payment = &$this->get();
    return $payment->pid;
  }
}

/**
* Defines the rules ms_order data type.
*/
class rules_data_type_ms_order extends rules_data_type {
  function load($oid) {
    return ms_core_order_load($oid);
  }
  
  function get_identifier() {
    $order = &$this->get();
    return $order->oid;
  }
}

/**
* Defines the rules order_status data type.
*/
class rules_data_type_order_status extends rules_data_type {
  /**
   * Gets the input form for the data
   * Implement it, if your data is not identifiable.
   */
  function get_default_input_form($info, $value) {
    return array(
      '#type' => 'select',
      '#title' => $info['label'],
      '#description' => t('Status'),
      '#options' => ms_core_get_order_statuses(),
      '#required' => TRUE,
      '#default_value' => $value,
    );
  }
}