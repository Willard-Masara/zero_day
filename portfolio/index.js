/* - here we have a node.js express server to serve an index.html 
 * - our backend also has the sqlite3 database that we will use to store reviews
 */


const express = require('express');
const path = require ('path');
const multer = require('multer');
const database = require('sqlite3').verbose();
const port = process.env.PORT || 3001;
const bodyParser = require('body-parser');
const app = express();

// connect db and fix file uploads
const db = new database.Database('database.db');

app.use(express.static(path.join(__dirname, 'public')));
app.use(bodyParser.urlencoded({extended: true}));

// we sort the routes here


app.get('/', (res, req)=>{

console.log('welcome home');
res.sendFile(__dirname, 'index.html');

});


app.post('/submit',(res, req)=>{
const message = req.body.message;
database,run("INSERT INTO messages (content) VALUES (?)", [message], function(err){
if(err){
console.log("Database error", err.message);
return res.status(500).send("Database error");
}
res.send('file uploaded successfully');
});
});


app.listen(port, () =>{

console.log(`Server listening on {port}`);

});
