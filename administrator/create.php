<?php
 session_start();
?>
<!DOCTYPE html>  
<head>
  <title>Administrator creates entries.</title>
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <style>li {list-style: none;}</style>
</head>
<body>
  <h2>Insert Entries:</h2>
  <ul>
    <form name="display" action="create.php" method="POST" >
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
  			echo "<ul><form name='insert' action='create.php' method='POST' > 
  			<li>Table:</li>  
    	  <li><input type='text' name='table' value = '$tableName'/></li> 
    	  <li>email:</li>  
    	  <li><input type='text' name='email'/></li>  
    	  <li>password:</li>  
    	  <li><input type='text' name='password'/></li>  
    	  <li>transaction_password</li>
    	  <li><input type='text' name='t_password'/></li>  
    	  <li>first_name:</li>  
    	  <li><input type='text' name='first_name'/></li>
    	  <li>last_name:</li>  
    	  <li><input type='text' name='last_name'/></li>
    	  <li>location(optional):</li>  
    	  <li><input type='text' name='location'/></li>
    	  <li><input type='submit' name='create' value = 'Insert'/></li>  
    	  </form>  
    	  </ul>";
      }
      if ($tableName == "project_initiated_by") {
  			echo "<ul><form name='insert' action='create.php' method='POST' > 
  			<li>Table:</li>  
    	  <li><input type='text' name='table' value = '$tableName'/></li> 
    	  <li>title:</li>  
    	  <li><input type='text' name='title'/></li>  
    	  <li>resourceurl(optional):</li>
    	  <li><input type='text' name='resourceurl'/></li>  
    	  <li>description:</li>  
    	  <li><input type='text' name='description'/></li>
    	  <li>startdate:</li>  
    	  <li><input type='date' name='startdate'/></li>
    	  <li>duration_of_months:</li>  
    	  <li><input type='number' name='duration_of_months'/></li>
    	  <li>funding_sought:</li>  
    	  <li><input type='number' name='funding_sought'/></li>
    	  <li>bank_account:</li>  
    	  <li><input type='text' name='bank_account'/></li>
    	  <li>country:</li>  
    	  <li><input type='text' name='country'/></li>
    	  <li>city:</li>  
    	  <li><input type='text' name='city'/></li>
    	  <li>initiator:</li>  
    	  <li><input type='text' name='initiator'/></li>
    	  <li><input type='submit' name='create' value = 'Insert'/></li>  
    	  </form>  
    	  </ul>";
      }
      
      if ($tableName == "fund") {
  			echo "<ul><form name='insert' action='create.php' method='POST' > 
  			<li>Table:</li>  
    	  <li><input type='text' name='table' value = '$tableName'/></li> 
    	  <li>transaction_id:</li>  
    	  <li><input type='text' name='transaction_id'/></li>  
    	  <li>bank_account:</li>  
    	  <li><input type='text' name='bank_account'/></li>  
    	  <li>funding_amount</li>
    	  <li><input type='number' name='funding_amount'/></li>  
    	  <li>funding_user(optional):</li>  
    	  <li><input type='text' name='funding_user'/></li>
    	  <li>funded_project(optional):</li>  
    	  <li><input type='number' name='funded_project'/></li>
    	  <li>timestamp_of_donation:</li>  
    	  <li><input type='text' name='timestamp_of_donation'/></li>
    	  <li><input type='submit' name='create' value = 'Insert'/></li>  
    	  </form>  
    	  </ul>";
      }
      
      if ($tableName == "category") {
  			echo "<ul><form name='insert' action='create.php' method='POST' >  
  			<li>Table:</li>  
    	  <li><input type='text' name='table' value = '$tableName'/></li> 
    	  <li>category_name:</li>  
    	  <li><input type='text' name='category_name'/></li>
    	  <li><input type='submit' name='create' value = 'Insert'/></li>  
    	  </form>  
    	  </ul>";
      }
      
      if ($tableName == "belong_to") {
  			echo "<ul><form name='insert' action='create.php' method='POST' >  
  			<li>Table:</li>  
    	  <li><input type='text' name='table' value = '$tableName'/></li> 
    	  <li>category:</li>  
    	  <li><input type='text' name='category'/></li>
    	  <li>projectid:</li>  
    	  <li><input type='text' name='projectid'/></li>
    	  <li><input type='submit' name='create' value = 'Insert'/></li>  
    	  </form>  
    	  </ul>";
      }
      
      if ($tableName == "administrators") {
  			echo "<ul><form name='insert' action='create.php' method='POST' > 
  			<li>Table:</li>  
    	  <li><input type='text' name='table' value = '$tableName'/></li> 
    	  <li>accountid:</li>  
    	  <li><input type='text' name='accountid'/></li>
    	  <li>password:</li>  
    	  <li><input type='text' name='password'/></li>
    	  <li><input type='submit' name='create' value = 'Insert'/></li>  
    	  </form>  
    	  </ul>";
      }
    }
    
    if (isset($_POST['create'])) {
      if ($_POST[table] == "users") {
        $result = pg_query($db, "INSERT INTO users VALUES(
									'$_POST[email]',
									'$_POST[password]', 
									'$_POST[t_password]',
									'$_POST[first_name]', 
									'$_POST[last_name]', 
									'$_POST[location]')"); 
				if (!$result) {
          echo "Insert failed!";
        } else {
          echo "Insert successful!";
        }
      }
      
      if ($_POST[table] == "project_initiated_by") {
        $maxIndex = pg_query($db, "
						    SELECT MAX(projectid) 
						    FROM project_initiated_by"
						  );
				$indexValue = pg_fetch_row($maxIndex);
				$thisIndex = $indexValue[0] + 1;
        $result = pg_query($db, "INSERT INTO project_initiated_by VALUES(
									$thisIndex,
									'$_POST[title]', 
									'$_POST[resourceurl]',
									'$_POST[description]', 
									'$_POST[startdate]', 
									$_POST[duration_of_months],
									0,
									0,
									$_POST[funding_sought],
									'$_POST[bank_account]',
									'ONGOING',
									'$_POST[country]',
									'$_POST[city]',
									'$_POST[initiator]')"); 
				if (!$result) {
          echo "Insert failed!";
        } else {
          echo "Insert successful!";
        }
      }
      
      if ($_POST[table] == "fund") {
        $result = pg_query($db, "INSERT INTO fund VALUES(
									'$_POST[transaction_id]',
									'$_POST[bank_account]', 
									$_POST[funding_amount],
									'$_POST[funding_user]', 
									'$_POST[funded_project]', 
									'$_POST[location]')"); 
				if (!$result) {
          echo "Insert failed!";
        } else {
          echo "Insert successful!";
        }
      }
      
      if ($_POST[table] == "category") {
        $result = pg_query($db, "INSERT INTO category VALUES(
									'$_POST[category_name]')"); 
				if (!$result) {
          echo "Insert failed!";
        } else {
          echo "Insert successful!";
        }
      }
      
      if ($_POST[table] == "belong_to") {
        $result = pg_query($db, "INSERT INTO belong_to VALUES(
									'$_POST[category]', 
									'$_POST[projectid]')"); 
				if (!$result) {
          echo "Insert failed!";
        } else {
          echo "Insert successful!";
        }
      }
      
      if ($_POST[table] == "administrators") {
        $result = pg_query($db, "INSERT INTO administrators VALUES(
									'$_POST[accountid]', 
									'$_POST[password]')"); 
				if (!$result) {
          echo "Insert failed!";
        } else {
          echo "Insert successful!";
        }
      }
    }
    ?>  
</body>
</html>
