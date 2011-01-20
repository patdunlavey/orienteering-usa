<?php
// $Id: $
/**
 * @file
 */

class ms_membership_roles_handler extends views_handler_field {
  function render($values) {
    $user_roles = user_roles();
    $roles_raw = unserialize($values->{$this->field_alias});
    $role_names = array();
    foreach ($roles_raw as $rid) {
      if ($rid) {
        $role_names[] = $user_roles[$rid];
      }
    }
    return implode(', ', $role_names);
  }
}