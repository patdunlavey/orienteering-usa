<?php

// ======================================
// CONDITIONS
// ======================================

/* 
* Conditions:
* + Check if user has a membership
* - Check the status of a membership
*/ 

/**
* Implementation of hook_rules_condition_info().
* @ingroup rules
*/
function ms_membership_rules_condition_info() {
  return array(
    'ms_membership_condition_user_has_membership' => array(
      'label' => t('Check if user has membership'),
      'arguments' => array(
        'mpid' => array('type' => 'mpid', 'label' => t('Membership Plan')),
        'account' => array('type' => 'user', 'label' => t('User'))
      ),
      'module' => 'Membership Suite',
    ),
  );
}

/**
* Condition: Check if a user has the membership
*/
function ms_membership_condition_user_has_membership($mpid, $account) {
  if (ms_membership_user_has_membership($account->uid, $mpid)) {
    return TRUE;
  }
  return FALSE;
}

// ======================================
// ACTIONS
// ======================================

/* 
* Actions:
* + Add Membership to User
* + Set Expiration Date for User Membership
* + Change Membership Status (Active, Cancelled, EOT, etc)
* - Load Membership from User
* - Load Membership Plan
*/

/**
* Implementation of hook_rules_action_info().
* @ingroup rules
*/
function ms_membership_rules_action_info() {
  return array(
    'ms_membership_action_add_membership' => array(
      'label' => t('Add a Membership to a User'),
      'arguments' => array(
        'mpid' => array('type' => 'mpid', 'label' => t('Membership Plan')),
        'account' => array('type' => 'user', 'label' => t('User')),
      ),
      'new variables' => array(
        'membership' => array(
          'type' => 'ms_membership',
          'label' => t('New membership'),
        ),
      ),
      'module' => 'Membership Suite',
    ),
    'ms_membership_action_add_membership_by_id' => array(
      'label' => t('Add a Membership to a User by Plan ID'),
      'arguments' => array(
        'mpid' => array('type' => 'number', 'label' => t('Membership Plan ID')),
        'account' => array('type' => 'user', 'label' => t('User')),
      ),
      'new variables' => array(
        'membership' => array(
          'type' => 'ms_membership',
          'label' => t('New membership'),
        ),
      ),
      'module' => 'Membership Suite',
    ),
    'ms_membership_action_change_membership_expiration' => array(
      'label' => t('Change the Expiration Date of a Membership'),
      'arguments' => array(
        'membership' => array('type' => 'ms_membership', 'label' => t('Membership')),
        'expiration' => array('type' => 'date', 'label' => t('Date')),
      ),
      'module' => 'Membership Suite',
    ),
    'ms_membership_action_change_membership_status' => array(
      'label' => t('Change the Status of a Membership'),
      'arguments' => array(
        'membership' => array('type' => 'ms_membership', 'label' => t('Membership')),
        'status' => array('type' => 'membership_status', 'label' => t('Status')),
      ),
      'module' => 'Membership Suite',
    ),
  );
}

/**
* Action: Change the status of a membership
*/
function ms_membership_action_change_membership_status($membership, $status) {
  // Change the Membership Status
  return ms_membership_change_membership_status($membership->mid, $status);
}

/**
* Action: Add a membership to a user
*/
function ms_membership_action_add_membership($mpid, $account) {
  $m_plan = ms_membership_load_membership_plan($mpid);
  // Add a new membership for this user
  $membership = ms_membership_insert_new_membership($m_plan, $account);
  // Add and remove the roles at the start of the membership
  ms_membership_change_roles($account->uid, $m_plan->start_grant_roles, $m_plan->start_remove_roles);
  return array('membership' => $membership);
}

/**
* Action: Add a membership to a user
*/
function ms_membership_action_add_membership_by_id($mpid, $account) {
  $m_plan = ms_membership_load_membership_plan($mpid);
  // Add a new membership for this user
  $membership = ms_membership_insert_new_membership($m_plan, $account);
  // Add and remove the roles at the start of the membership
  ms_membership_change_roles($account->uid, $m_plan->start_grant_roles, $m_plan->start_remove_roles);
  return array('membership' => $membership);
}

/**
* Action: Change the expiration date of a membership
*/
function ms_membership_action_change_membership_expiration($membership, $expiration) {
  return ms_membership_change_membership_expiration($membership->mid, strtotime($expiration));
}

// ======================================
// TRIGGERS
// ======================================

/* 
* Triggers:
* + Membership is added to a user
* + Membership is expiring
* + Membership is cancelled
* + Membership has a payment
*/ 

/**
 * Implementation of hook_rules_event_info()
 */
function ms_membership_rules_event_info() {
  $items = array(
    'ms_membership_event_membership_cancel' => array(
      'label' => t('Membership Cancelled'),
      'module' => 'Membership Suite',
      'help' => t("Triggers when a membership is cancelled."),
      'arguments' => array(
        'account' => array('type' => 'user', 'label' => t('Membership Account')),
        'membership' => array('type' => 'ms_membership', 'label' => t('Membership')),
        'm_plan' => array('type' => 'ms_membership_plan', 'label' => t('Membership Plan')),
      ),
    ),
    'ms_membership_event_membership_signup' => array(
      'label' => t('Membership Signup'),
      'module' => 'Membership Suite',
      'help' => t("Triggers when a user signs up for a new membership."),
      'arguments' => array(
        'account' => array('type' => 'user', 'label' => t('Membership Account')),
        'membership' => array('type' => 'ms_membership', 'label' => t('Membership')),
        'm_plan' => array('type' => 'ms_membership_plan', 'label' => t('Membership Plan')),
      ),
    ),
    'ms_membership_event_membership_payment' => array(
      'label' => t('Membership Payment'),
      'module' => 'Membership Suite',
      'help' => t("Triggers when a payment is received for a membership."),
      'arguments' => array(
        'account' => array('type' => 'user', 'label' => t('Membership Account')),
        'membership' => array('type' => 'ms_membership', 'label' => t('Membership')),
        'm_plan' => array('type' => 'ms_membership_plan', 'label' => t('Membership Plan')),
      ),
    ),
    'ms_membership_event_membership_expiring' => array(
      'label' => t('Membership Expiring'),
      'module' => 'Membership Suite',
      'help' => t("Triggers when a membership is expiring."),
      'arguments' => array(
        'account' => array('type' => 'user', 'label' => t('Membership Account')),
        'membership' => array('type' => 'ms_membership', 'label' => t('Membership')),
        'm_plan' => array('type' => 'ms_membership_plan', 'label' => t('Membership Plan')),
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
function ms_membership_rules_data_type_info() {
  return array(
    'mpid' => array(
      'label' => t('Membership Plan'),
      'class' => 'rules_data_type_mpid',
      'savable' => FALSE,
      'identifiable' => FALSE,
      'uses_input_form' => TRUE,
      'module' => 'Membership Suite',
    ),
    'membership_status' => array(
      'label' => t('Membership Status'),
      'class' => 'rules_data_type_membership_status',
      'savable' => FALSE,
      'identifiable' => FALSE,
      'uses_input_form' => TRUE,
      'module' => 'Membership Suite',
    ),
    'ms_membership_plan' => array(
      'label' => t('Membership Plan'),
      'class' => 'rules_data_type_ms_membership_plan',
      'savable' => FALSE,
      'identifiable' => TRUE,
      'uses_input_form' => FALSE,
      'module' => 'Membership Suite',
    ),
    'ms_membership' => array(
      'label' => t('Membership'),
      'class' => 'rules_data_type_membership',
      'savable' => FALSE,
      'identifiable' => TRUE,
      'uses_input_form' => FALSE,
      'module' => 'Membership Suite',
    ),
  );
}

/**
* Defines the rules membership data type.
*/
class rules_data_type_membership extends rules_data_type {
  function load($mid) {
    return ms_membership_load_membership($mid);
  }
  
  function get_identifier() {
    $membership = &$this->get();
    return $membership->mid;
  }
}

/**
* Defines the rules ms_membership_plan data type.
*/
class rules_data_type_ms_membership_plan extends rules_data_type {
  function load($mpid) {
    return ms_membership_load_membership_plan($mpid);
  }
  
  function get_identifier() {
    $m_plan = &$this->get();
    return $m_plan->mpid;
  }
}

/**
* Defines the rules mpid data type.
*/
class rules_data_type_mpid extends rules_data_type {
  /**
   * Gets the input form for the data
   * Implement it, if your data is not identifiable.
   */
  function get_default_input_form($info, $value) {
    return array(
      '#type' => 'select',
      '#title' => $info['label'],
      '#description' => t('Select a Membership Plan.'),
      '#options' => ms_membership_get_plans(),
      '#required' => TRUE,
      '#default_value' => $value,
    );
  }
}

/**
* Defines the rules membership_status data type.
*/
class rules_data_type_membership_status extends rules_data_type {
  /**
   * Gets the input form for the data
   * Implement it, if your data is not identifiable.
   */
  function get_default_input_form($info, $value) {
    return array(
      '#type' => 'select',
      '#title' => $info['label'],
      '#description' => t('Status'),
      '#options' => ms_membership_get_membership_statuses(),
      '#required' => TRUE,
      '#default_value' => $value,
    );
  }
}
