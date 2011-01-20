<div class="footcol first">
<h2 class="foot-title">About Us</h2>
<?php
$tree = menu_tree_page_data('menu-about-ousa');
echo menu_tree_output($tree);
?>
</div>

<div class="footcol">
<h2 class="foot-title"><a href="/documents" >Documents</a></h2>
<?php
$tree = menu_tree_page_data('menu-documents');
echo menu_tree_output($tree);
?>
</div>

<!--<div class="footcol">
<h2 class="foot-title"><a href="http://www.us.orienteering.org/binder" target="_blank">Documents</a></h2>
<ul class="menu"><li class="leaf first"><a href="http://www.us.orienteering.org/binder/admdocs.html" title="" target="_blank">Administrative</a></li>
<li class="leaf"><a href="http://www.us.orienteering.org/binder/agm.html" title="" target="_blank">Annual General Meeting</a></li>
<li class="leaf"><a href="http://www.us.orienteering.org/binder/funds.html" title="" target="_blank">Fund Policies</a></li>
<li class="leaf"><a href="http://www.us.orienteering.org/binder/admpol.html" title="" target="_blank">Administrative Policies</a></li>
<li class="leaf"><a href="http://www.us.orienteering.org/binder/history.html" title="" target="_blank">History / Competition</a></li>
<li class="leaf last"><a href="http://www.us.orienteering.org/binder/board.html" title="" target="_blank">Board of Directors</a></li>

</ul></div>-->


<div class="footcol last">
<h2 class="foot-title">Contact</h2>
<?php
$tree = menu_tree_page_data('menu-contact');
echo menu_tree_output($tree);
?>
</div>



