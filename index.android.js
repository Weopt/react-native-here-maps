/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 * @flow
 */

import React, { Component } from 'react';
import { AppRegistry } from 'react-native';

import MapView from './MapView';

export default class HereMapsRN extends Component {

  render() {
    return (

      <MapView
        style={{flex : 1, backgroundColor: '#FFF'}}
        center="43.734453,7.423343"
        markersList={[
          {
            location: '43.738769,7.421140',
            title: 'We Opt',
            description: '10 bd Princesse Charlotte\nLe Windsor\n\nMonaco'
          },
          {
            location: '43.739207,7.428086',
            title: 'Casino de Monte-Carlo',
            description: 'Place du Casino\n\nMonaco'
          },
          
        ]}
        mapType="normal"
        initialZoom={15} />
    );
  }
}

AppRegistry.registerComponent('HereMapsRN', () => HereMapsRN);
