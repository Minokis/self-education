import React from 'react';
import SupervisorsListContainer from './../containers/SupervisorsListContainer';

const SUPERVISORS = [
  {id: 701, userId: "LameAndVeryVeryVeryVeryLongNickName", guestId: 123456789012},
  {id: 702, userId: "LisaNordicFox", guestId: 234567890123},
  {id: 703, userId: "xX-shadow-Xx", guestId: 345678901234}
];

const USER = {id: 700, userId: "ItsMe", guestId: 567890123456};

export default class SupervisorsListPage extends React.Component {
  render() {
    return (
      <div>
      	<h3>Нужен стимул?</h3>
        <SupervisorsListContainer supervisors={SUPERVISORS} user={USER} />
      </div>
    );
  }
}
