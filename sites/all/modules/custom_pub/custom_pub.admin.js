/* $Id: custom_pub.admin.js,v 1.1 2010/01/20 21:13:05 arcaneadam Exp $ */
Drupal.behaviors.custom_pub_admin = function() {
	$("td.custom_pub-option-edit-cell").html('<a href="#">Edit</a>').css("text-align","right");
	$("tr.custom_pub-form-edit").hide();
	$("td.custom_pub-option-edit-cell > a").bind('click',function(){
		$this = $(this);
		$opt = new Array();
		$opt["Edit"] = "Close";
		$opt["Close"] = "Edit";
		$this.parents('tr.custom_pub-option-row').next("tr.custom_pub-form-edit").toggle();
		$txt = $this.text();
		$this.text($opt[$txt]);
		return false;
	});
}
