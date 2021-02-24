<?php
session_start();
//清空session信息
$_SESSION['login'] = array();

//清楚客户端sessionid
if(isset($_COOKIE[session_name()])){
    setCookie(session_name(),'',time()-3600,'/');
}

//彻底销毁session
session_destroy();

//返回登录页
header("Location:login.php");

?>