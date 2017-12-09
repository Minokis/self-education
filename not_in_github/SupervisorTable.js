import React from 'react'

class SupervisorRow extends React.Component {
	render() {
		const supervisor = this.props.supervisor;
		return(
			<tr>
        		<td>{supervisor.userId}</td>
        		<td>
        			<button type="button" class="btn" >Удалить</button>
        		</td>
      		</tr>
			);
	}
}

export default class SupervisorTable extends React.Component {
  render() {
    const rows = [];

    this.props.supervisors.forEach((supervisor) => {
        rows.push(
          <SupervisorRow
            supervisor={supervisor}
            key={supervisor.id} />
        );
    });

    return (
      <table>
        <thead>
          <tr>
            <th colSpan="2">Тебя поддерживают:</th>
          </tr>
        </thead>
        <tbody>{rows}</tbody>
      </table>
    );
  }
}
