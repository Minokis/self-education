import React from 'react';
import UserGuestIdRow from './../components/UserGuestIdRow';
import AddSupervisorForm from './../components/AddSupervisorForm';
import SupervisorTable from './../components/SupervisorTable';
// import {todoService} from "./../appContext/Context";
// import DateUtils from './../utils/DateUtils';
// import {add, update} from './../store/server/todo/Actions';

export default class SupervisorsListContainer extends React.Component {
  constructor(props) {
    super(props);
  }

  render() {
    return (
      <div>
          <UserGuestIdRow user={this.props.user}/>
          <AddSupervisorForm />
          <SupervisorTable supervisors={this.props.supervisors} />
          <div class="col-4">
      	     <button type="button" class="btn">Назад к моим задачам</button>
          </div>
      </div>
    );
  }


}
