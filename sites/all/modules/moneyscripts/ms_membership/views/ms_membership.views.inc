<?php
// $Id: $
/**
 * @file
 * Provide Views support
 */

/**
 * Implementation of hook_views_data().
 */
function ms_membership_views_data() {
  $data = array();

   // Definitions for ms_membership_plans
  $data['ms_membership_plans']['table']['group'] = t('Membership Plan');
  
  $data['ms_membership_plans']['table']['base'] = array(
    'field' => 'mpid',
    'title' => t('Membership Plan'),
    'help' => t("Create Membership Plans Related Views"),
    'weight' => -10,
  );
  
  $ms_membership_plans = drupal_get_schema('ms_membership_plans');
  //serial
  $data['ms_membership_plans']['mpid'] = array(
    'title' => 'ID',
    'help' => $ms_membership_plans['fields']['mpid']['description'],
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
  $data['ms_membership_plans']['name'] = array(
    'title' => 'Name',
    'help' => $ms_membership_plans['fields']['name']['description'],
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
  $data['ms_membership_plans']['description'] = array(
    'title' => 'Description',
    'help' => $ms_membership_plans['fields']['description']['description'],
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
  $data['ms_membership_plans']['main_amount'] = array(
    'title' => 'Main Amount',
    'help' => $ms_membership_plans['fields']['main_amount']['description'],
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
  $data['ms_membership_plans']['main_length'] = array(
    'title' => 'Main Length',
    'help' => $ms_membership_plans['fields']['main_length']['description'],
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
  $data['ms_membership_plans']['main_unit'] = array(
    'title' => 'Main Unit',
    'help' => $ms_membership_plans['fields']['main_unit']['description'],
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
  $data['ms_membership_plans']['trial_amount'] = array(
    'title' => 'Trial Amount',
    'help' => $ms_membership_plans['fields']['trial_amount']['description'],
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
  $data['ms_membership_plans']['trial_length'] = array(
    'title' => 'Trial Length',
    'help' => $ms_membership_plans['fields']['trial_length']['description'],
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
  $data['ms_membership_plans']['trial_unit'] = array(
    'title' => 'Trial Unit',
    'help' => $ms_membership_plans['fields']['trial_unit']['description'],
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
  $data['ms_membership_plans']['recurring'] = array(
    'title' => 'Recurring?',
    'help' => $ms_membership_plans['fields']['recurring']['description'],
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
  //int
  $data['ms_membership_plans']['total_occurrences'] = array(
    'title' => 'Total Occurrences',
    'help' => $ms_membership_plans['fields']['total_occurrences']['description'],
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
  $data['ms_membership_plans']['buynow'] = array(
    'title' => 'Add to Cart URL',
    'help' => 'A url to where the user can purchase the membership',
    'field' => array(
        'handler' => 'ms_membership_buynow_handler',
        'click sortable' => TRUE,
        'field' => 'mpid',
    ),
  );
  //varchar
  $data['ms_membership_plans']['signup_mail_subject'] = array(
    'title' => 'Signup Mail Subject',
    'help' => $ms_membership_plans['fields']['signup_mail_subject']['description'],
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
  $data['ms_membership_plans']['signup_mail_body'] = array(
    'title' => 'Signup Mail Body',
    'help' => $ms_membership_plans['fields']['signup_mail_body']['description'],
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
  $data['ms_membership_plans']['eot_mail_subject'] = array(
    'title' => 'EOT Mail Subject',
    'help' => $ms_membership_plans['fields']['eot_mail_subject']['description'],
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
  $data['ms_membership_plans']['eot_mail_body'] = array(
    'title' => 'EOT Mail Body',
    'help' => $ms_membership_plans['fields']['eot_mail_body']['description'],
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
  $data['ms_membership_plans']['cancel_mail_subject'] = array(
    'title' => 'Cancel Mail Subject',
    'help' => $ms_membership_plans['fields']['cancel_mail_subject']['description'],
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
  $data['ms_membership_plans']['cancel_mail_body'] = array(
    'title' => 'Cancel Mail Body',
    'help' => $ms_membership_plans['fields']['cancel_mail_body']['description'],
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
  $data['ms_membership_plans']['modify_mail_subject'] = array(
    'title' => 'Modify Mail Subject',
    'help' => $ms_membership_plans['fields']['modify_mail_subject']['description'],
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
  $data['ms_membership_plans']['modify_mail_body'] = array(
    'title' => 'Modify Mail Body',
    'help' => $ms_membership_plans['fields']['modify_mail_body']['description'],
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
  $data['ms_membership_plans']['expiring_mail_subject'] = array(
    'title' => 'Expiring Mail Subject',
    'help' => $ms_membership_plans['fields']['expiring_mail_subject']['description'],
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
  $data['ms_membership_plans']['expiring_mail_body'] = array(
    'title' => 'Expiring Mail Body',
    'help' => $ms_membership_plans['fields']['expiring_mail_body']['description'],
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
  $data['ms_membership_plans']['expiring_mail_days'] = array(
    'title' => 'Expiring Mail Days',
    'help' => $ms_membership_plans['fields']['expiring_mail_days']['description'],
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
  $data['ms_membership_plans']['start_grant_roles'] = array(
    'title' => 'Start Grant Roles',
    'help' => $ms_membership_plans['fields']['start_grant_roles']['description'],
    'field' => array(
        'handler' => 'ms_membership_roles_handler',
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
  $data['ms_membership_plans']['start_remove_roles'] = array(
    'title' => 'Start Remove Roles',
    'help' => $ms_membership_plans['fields']['start_remove_roles']['description'],
    'field' => array(
        'handler' => 'ms_membership_roles_handler',
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
  $data['ms_membership_plans']['expire_grant_roles'] = array(
    'title' => 'Expire Grant Roles',
    'help' => $ms_membership_plans['fields']['expire_grant_roles']['description'],
    'field' => array(
        'handler' => 'ms_membership_roles_handler',
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
  $data['ms_membership_plans']['expire_remove_roles'] = array(
    'title' => 'Expire Remove Roles',
    'help' => $ms_membership_plans['fields']['expire_remove_roles']['description'],
    'field' => array(
        'handler' => 'ms_membership_roles_handler',
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
  $data['ms_membership_plans']['weight'] = array(
    'title' => 'Weight',
    'help' => $ms_membership_plans['fields']['weight']['description'],
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
  $data['ms_membership_plans']['allow_roles'] = array(
    'title' => 'Allowed Roles',
    'help' => $ms_membership_plans['fields']['allow_roles']['description'],
    'field' => array(
        'handler' => 'ms_membership_roles_handler',
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
  $data['ms_membership_plans']['register_urls'] = array(
    'title' => 'Special URLs',
    'help' => $ms_membership_plans['fields']['register_urls']['description'],
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
  $data['ms_membership_plans']['expire_when'] = array(
    'title' => 'Expire When?',
    'help' => $ms_membership_plans['fields']['expire_when']['description'],
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
  $data['ms_membership_plans']['show_registration'] = array(
    'title' => 'Show on Registration Page?',
    'help' => $ms_membership_plans['fields']['show_registration']['description'],
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
  //int
  $data['ms_membership_plans']['show_account'] = array(
    'title' => 'Show on Account Page?',
    'help' => $ms_membership_plans['fields']['show_account']['description'],
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
 // Definitions for ms_memberships
  $data['ms_memberships']['table']['group'] = t('Membership');
  
  $data['ms_memberships']['table']['base'] = array(
    'field' => 'mid',
    'title' => t('Membership'),
    'help' => t("Create Membership Related Views"),
    'weight' => -10,
  );
  
  $ms_memberships = drupal_get_schema('ms_memberships');
  //serial
  $data['ms_memberships']['mid'] = array(
    'title' => 'ID',
    'help' => $ms_memberships['fields']['mid']['description'],
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
  $data['ms_orders']['table']['join'] = array(
    'ms_memberships' => array(
      'left_field' => 'oid',
      'field' => 'oid',
      'type' => 'INNER',
    ), 
  );
  $data['users']['table']['join'] = array(
    'ms_memberships' => array(
      'left_field' => 'uid',
      'field' => 'uid',
      'type' => 'RIGHT',
    ), 
  );
  $data['ms_memberships']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
      'type' => 'LEFT',
    ), 
  );
  $data['users_roles']['table']['join'] = array(
    'ms_memberships' => array(
      'left_field' => 'uid',
      'field' => 'uid',
      'type' => 'INNER',
    ), 
  );
  $data['ms_membership_plans']['table']['join'] = array(
    'ms_memberships' => array(
      'left_field' => 'mpid',
      'field' => 'mpid',
      'type' => 'LEFT',
    ), 
  );
  //int
  $data['ms_memberships']['status'] = array(
    'title' => 'Status',
    'help' => $ms_memberships['fields']['status']['description'],
    'field' => array(
        'handler' => 'ms_membership_status_handler',
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
  //int
  $data['ms_memberships']['expiration'] = array(
    'title' => 'Expiration Date',
    'help' => $ms_memberships['fields']['expiration']['description'],
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
  $data['ms_memberships']['start_date'] = array(
    'title' => 'Start Date',
    'help' => $ms_memberships['fields']['start_date']['description'],
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
  $data['ms_memberships']['current_payments'] = array(
    'title' => 'Current Payments',
    'help' => $ms_memberships['fields']['current_payments']['description'],
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
  //int
  $data['ms_memberships']['max_payments'] = array(
    'title' => 'Max Payments',
    'help' => $ms_memberships['fields']['max_payments']['description'],
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

  
  return $data;
}
