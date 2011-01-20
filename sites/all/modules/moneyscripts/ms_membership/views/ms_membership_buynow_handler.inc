<?php
// $Id: $
/**
 * @file
 */

class ms_membership_buynow_handler extends views_handler_field {
  function render($values) {
    global $user;
    $m_plan = ms_membership_load_membership_plan($values->mpid);
    
    return url('membership/purchase/'. $m_plan->mpid);
  }
}