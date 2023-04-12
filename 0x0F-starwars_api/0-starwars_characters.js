#!/usr/bin/node
const movieId = process.argv[2];
const request = require('request');
const data = JSON.parse(response.body);
const charsData = data.characters;

const url = `https://swapi-api.hbtn.io/api/films/${movieId}`;
request(url, async (err, response) => {
  if (err) {
    console.error(err);
  }
  for (const charId in charsData) {
    await new Promise((resolve, reject) => {
      request(charsData[charId], function (err, response) {
        if (err) {
          console.log(err);
        }
        const charData = JSON.parse(response.body);
        console.log(charData.name);
        resolve();
      });
    });
  }
});
