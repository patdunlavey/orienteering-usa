<div class="sc_menu">
  <ul class="sc_menu">
    <?php foreach ($rows as $id => $row): ?>
      <li class="<?php print $classes[$id]; ?>"><?php print $row; ?></li>
    <?php endforeach; ?>
  </ul>
 </div>