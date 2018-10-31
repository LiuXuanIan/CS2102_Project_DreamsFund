<?php
 session_start();
?>
<!DOCTYPE html>  
<head>
  <title>Administrator deletes entries.</title>
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <style>li {list-style: none;}</style>
</head>
<body>
  <h2>Delete Entries:</h2>
  <ul>
    <form name="display" action="delete.php" method="POST" >
      <div class="row form-group">
				<div class="col-md-6">
						<label for="table">Table</label>
				</div>
				<div class="col-md-12">
					<select id="table" name="table">
					  <option value="users">users</option>
					  <option value="project_initiated_by">project_initiated_by</option>
						<option value="fund">fund</option>
						<option value="category">category</option>
						<option value="belong_to">belong_to</option>
						<option value="administrators">administrators</option>
					</select>
				</div>
			</div>
      <li><input type="submit" name="submit" /></li>
    </form>
  </ul>
  <?php
    $db     = pg_connect("host=localhost port=5432 dbname=CrowdFunding user=postgres password=liu");	
    $tableName = "$_POST[table]";
    if (isset($_POST['submit'])) {
      if ($tableName == "users") {
  			echo "<ul><form name='update' action='delete.php' method='POST' > 
  			<li>Table:</li>  
    	  <li><input type='text' name='table' value = '$tableName'/></li> 
    	  <li>email:</li>  
    	  <li><input type='text' name='email'/></li>  
    	  <li><input type='submit' name='delete' value = 'Delete'/></li>
    	  </form>  
    	  </ul>";
      }
      if ($tableName == "project_initiated_by") {
  			echo "<ul><form name='update' action='delete.php' method='POST' > 
  			<li>Table:</li>  
    	  <li><input type='text' name='table' value = '$tableName'/></li> 
    	  <li>projectid:</li>  
    	  <li><input type='number' name='projectid'/></li>
    	  <li><input type='submit' name='delete' value = 'Delete'/></li>  
    	  </form>  
    	  </ul>";
      }
      
      if ($tableName == "fund") {
  			echo "<ul><form name='update' action='delete.php' method='POST' > 
  			<li>Table:</li>  
    	  <li><input type='text' name='table' value = '$tableName'/></li> 
    	  <li>transaction_id:</li>  
    	  <li><input type='text' name='transaction_id'/></li>  
    	  <li><input type='submit' name='delete' value = 'Delete'/></li>  
    	  </form>  
    	  </ul>";
      }
      
      if ($tableName == "category") {
  			echo "<ul><form name='update' action='delete.php' method='POST' >
  			<li>Table:</li>  
    	  <li><input type='text' name='table' value = '$tableName'/></li>
    	  <li>category_name:</li>  
    	  <li><input type='text' name='category_name'/></li>
    	  <li><input type='submit' name='delete' value = 'Delete'/></li>
    	  </form>  
    	  </ul>";
      }
      
      if ($tableName == "belong_to") {
  			echo "<ul><form name='update' action='delete.php' method='POST' >  
  			<li>Table:</li>  
    	  <li><input type='text' name='table' value = '$tableName'/></li> 
    	  <li>category:</li>  
    	  <li><input type='text' name='category'/></li>
    	  <li>projectid:</li>  
    	  <li><input type='text' name='projectid'/></li>
    	  <li><input type='submit' name='delete' value = 'Delete'/></li>  
    	  </form>  
    	  </ul>";
      }
      
      if ($tableName == "administrators") {
  			echo "<ul><form name='update' action='delete.php' method='POST' > 
  			<li>Table:</li>  
    	  <li><input type='text' name='table' value = '$tableName'/></li> 
    	  <li>accountid:</li>  
    	  <li><input type='text' name='accountid'/></li>
    	  <li>password:</li>  
    	  <li><input type='text' name='password'/></li>
    	  <li><input type='submit' name='delete' value = 'Delete'/></li>  
    	  </form>  
    	  </ul>";
      }
    }
    
    if (isset($_POST['delete'])) {
      if ($_POST[table] == "users") {
        $result = pg_query($db, "DELETE FROM users WHERE
									email = '$_POST[email]'"); 
				if (!$result) {
          echo "Delete failed!";
        } else {
          echo "Delete successful!";
        }
      }
      
      if ($_POST[table] == "project_initiated_by") {
        $result = pg_query($db, "DELETE FROM project_initiated_by WHERE
									projectid = '$_POST[projectid]'");
				if (!$result) {
          echo "Delete failed!";
        } else {
          echo "Delete successful!";
        }
      }
      
      if ($_POST[table] == "fund") {
        $result = pg_query($db, "DELETE FROM fund WHERE
									transaction_id = '$_POST[transaction_id]'"); 
				if (!$result) {
          echo "Delete failed!";
        } else {
          echo "Delete successful!";
        }
      }
      
      if ($_POST[table] == "category") {
        $result = pg_query($db, "DELETE FROM category WHERE
									category_name = '$_POST[category_name]'"); 
				if (!$result) {
          echo "Delete failed!";
        } else {
          echo "Delete successful!";
        }
      }
      
      if ($_POST[table] == "belong_to") {
        $result = pg_query($db, "DELETE FROM belong_to WHERE
									category = '$_POST[Ucategory]' AND
									projectid = '$_POST[Uprojectid]'"); 
				if (!$result) {
          echo "Delete failed!";
        } else {
          echo "Delete successful!";
        }
      }
      
      if ($_POST[table] == "administrators") {
        $result = pg_query($db, "DELETE FROM administrators WHERE
									accountid = '$_POST[Uaccountid]'"); 
				if (!$result) {
          echo "Delete failed!";
        } else {
          echo "Delete successful!";
        }
      }
    }
    ?>  
</body>
</html>
